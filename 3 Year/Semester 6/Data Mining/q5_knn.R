df_orig<-read.csv("./breast-cancer-wisconsin/breast-cancer-wisconsin.data", header = FALSE, stringsAsFactors = FALSE)

is.na(df_orig$V7)<- df_orig$V7 == "?"

temp<-df_orig[complete.cases(df_orig),] 

temp$V11<- as.factor(temp$V11)

temp$V7<-as.integer(temp$V7)

df<-temp
nrec<-nrow(df)
rm(df_orig, temp)
#install.packages("caTools")
library(caTools)
##Hold out method, 75% split
set.seed(1111)
split<-sample.split(df$V11, SplitRatio = 0.75)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

#summary(training_set[, c(1:10)])

fnormalize<-function(x){
  return((x-min(x))/(max(x)-min(x)))
}
num_col<-1:10
trainingKNN<- as.data.frame(lapply(training_set[,num_col], fnormalize))
trainingKNN<-cbind(trainingKNN, training_set$V11)
names(trainingKNN)[11]<-"V11"
rm(training_set)

testKNN<- as.data.frame(lapply(test_set[,num_col], fnormalize))
testKNN<-cbind(testKNN, test_set$V11)
names(testKNN)[11]<-"V11"
rm(test_set)

training_target<-trainingKNN[,11]
test_target<-testKNN[,11]
## purpose
#summary(trainingKNN[,num_rows])

#install.packages("class", dependencies = TRUE)

library(class)

m1<-knn(trainingKNN, testKNN, cl = training_target, k=13)

#install.packages("caret", dependencies = TRUE)
library(caret)

cfm<-confusionMatrix(test_target, m1)
cfm$overall['Accuracy']

#66.6% split
set.seed(2222)
split<-sample.split(df$V11, SplitRatio = 0.666)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

num_col<-1:10
trainingKNN<- as.data.frame(lapply(training_set[,num_col], fnormalize))
trainingKNN<-cbind(trainingKNN, training_set$V11)
names(trainingKNN)[11]<-"V11"
rm(training_set)

testKNN<- as.data.frame(lapply(test_set[,num_col], fnormalize))
testKNN<-cbind(testKNN, test_set$V11)
names(testKNN)[11]<-"V11"
rm(test_set)

training_target<-trainingKNN[,11]
test_target<-testKNN[,11]

m1<-knn(trainingKNN, testKNN, cl = training_target, k=13)

cfm<-confusionMatrix(test_target, m1)
cfm$overall['Accuracy']

# ## Random Subsampling, 75% split
acc<-c()
set.seed(3333)
for (i in 1:10){
  split<-sample.split(df$V11, SplitRatio = 0.75)
  training_set<-subset(df, split==TRUE)
  test_set<-subset(df, split==FALSE)
  
  num_col<-1:10
  trainingKNN<- as.data.frame(lapply(training_set[,num_col], fnormalize))
  trainingKNN<-cbind(trainingKNN, training_set$V11)
  names(trainingKNN)[11]<-"V11"
  rm(training_set)
  
  testKNN<- as.data.frame(lapply(test_set[,num_col], fnormalize))
  testKNN<-cbind(testKNN, test_set$V11)
  names(testKNN)[11]<-"V11"
  rm(test_set)
  
  training_target<-trainingKNN[,11]
  test_target<-testKNN[,11]
  
  m1<-knn(trainingKNN, testKNN, cl = training_target, k=13)

  cfm<-confusionMatrix(test_target, m1)
  acc<-c(acc,cfm$overall['Accuracy'])
}
cat("Average of accuracy: ",mean(acc))  #average of accuracy

# ## Random Subsampling, 66.6% split
acc<-c()
set.seed(4444)
for (i in 1:10){
  split<-sample.split(df$V11, SplitRatio = 0.666)
  training_set<-subset(df, split==TRUE)
  test_set<-subset(df, split==FALSE)
  num_col<-1:10
  trainingKNN<- as.data.frame(lapply(training_set[,num_col], fnormalize))
  trainingKNN<-cbind(trainingKNN, training_set$V11)
  names(trainingKNN)[11]<-"V11"
  rm(training_set)
  
  testKNN<- as.data.frame(lapply(test_set[,num_col], fnormalize))
  testKNN<-cbind(testKNN, test_set$V11)
  names(testKNN)[11]<-"V11"
  rm(test_set)
  
  training_target<-trainingKNN[,11]
  test_target<-testKNN[,11]
  
  m1<-knn(trainingKNN, testKNN, cl = training_target, k=13)
  
  cfm<-confusionMatrix(test_target, m1)
  acc<-c(acc,cfm$overall['Accuracy'])
}
cat("Average of accuracy: ",mean(acc))  #average of accuracy


## Cross validation

#75% split
## Cross validation
#75%
set.seed(5555)
split<-sample.split(df$V11, SplitRatio = 0.75)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-train(V11~., data = training_set, method='knn', trControl = trainControl(method = 'cv', number = 20))

p<-predict(model, test_set, method='class')

cfm<-confusionMatrix(test_set[,11], p)
cfm$overall['Accuracy']
#66.6%

set.seed(6666)
split<-sample.split(df$V11, SplitRatio = 0.666)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-train(V11~., data = training_set, method='knn', trControl = trainControl(method = 'cv', number = 20))

p<-predict(model, test_set, method='class')

cfm<-confusionMatrix(test_set[,11], p)
cfm$overall['Accuracy']
