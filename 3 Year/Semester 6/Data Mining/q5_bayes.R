df_orig<-read.csv("./breast-cancer-wisconsin/breast-cancer-wisconsin.data", header = FALSE, stringsAsFactors = FALSE)

is.na(df_orig$V7)<- df_orig$V7 == "?"

temp<-df_orig[complete.cases(df_orig),] 

temp$V11<- as.factor(temp$V11)

temp$V7<-as.integer(temp$V7)

df<-temp
nrec<-nrow(df)
rm(df_orig, temp)

# install.packages("e1071")
library(e1071)
library(caTools)
set.seed(1111)

##Hold out method, 75% split
split<-sample.split(df$V11, SplitRatio = 0.75)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-naiveBayes(training_set$V11~., data=training_set)
pred<-predict(model, test_set[,-11])

library(caret)

cfm<-confusionMatrix(pred,test_set$V11)
cfm$overall['Accuracy']

##Hold out method, 66% split
set.seed(2222)
split<-sample.split(df$V11, SplitRatio = 0.666)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-naiveBayes(training_set$V11~., data=training_set)
pred<-predict(model, test_set[,-11])

cfm<-confusionMatrix(pred,test_set$V11)
cfm$overall['Accuracy']


##Random Subsampling
#75%

acc<-c()
set.seed(3333)
for (i in 1:10){
  split<-sample.split(df$V11, SplitRatio = 0.75)
  training_set<-subset(df, split==TRUE)
  test_set<-subset(df, split==FALSE)
  
  model<-naiveBayes(training_set$V11~., data=training_set)
  pred<-predict(model, test_set[,-11])

  cfm<-confusionMatrix(pred,test_set$V11)
  acc<-c(acc,cfm$overall['Accuracy'])
}

cat("Average of accuracy: ",mean(acc))  #average of accuracy

#66.6%

acc<-c()
set.seed(4444)
for (i in 1:10){
  split<-sample.split(df$V11, SplitRatio = 0.666)
  training_set<-subset(df, split==TRUE)
  test_set<-subset(df, split==FALSE)
  
  model<-naiveBayes(training_set$V11~., data=training_set)
  pred<-predict(model, test_set[,-11])
  
  cfm<-confusionMatrix(pred,test_set$V11)
  acc<-c(acc,cfm$overall['Accuracy'])
}

cat("Average of accuracy: ",mean(acc))  #average of accuracy


## Cross validation
#75%

#install.packages("naivebayes") #for naive bayes
library(naivebayes)
set.seed(5555)
split<-sample.split(df$V11, SplitRatio = 0.75)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-train(V11~., data = training_set, method='naive_bayes', trControl = trainControl(method = 'cv', number = 10))

p<-predict(model, test_set, method='class')

cfm<-confusionMatrix(test_set[,11], p)
cfm$overall['Accuracy']

#66.6%
library(naivebayes)
set.seed(6666)
split<-sample.split(df$V11, SplitRatio = 0.666)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-train(V11~., data = training_set, method='naive_bayes', trControl = trainControl(method = 'cv', number = 10))

p<-predict(model, test_set, method='class')

cfm<-confusionMatrix(test_set[,11], p)
cfm$overall['Accuracy']
