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
set.seed(1111)
##Hold out method, 75% split
split<-sample.split(df$V11, SplitRatio = 0.75)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

#install.packages("rpart")
#install.packages("rpart.plot")
library(rpart)
library(rpart.plot)

dtm<-rpart(V11~.,training_set, method = "class")
#rpart.plot(dtm)
#rpart.plot(dtm, type=4, extra = 101)

p<-predict(dtm, test_set, type = "class")

#install.packages("caret", dependencies = TRUE)
library(caret)

confusionMatrix(test_set[,11], p)
#accuracy = 0.9474


##Hold out method, 66.66% split
set.seed(2222)
split<-sample.split(df$V11, SplitRatio = 0.666)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

dtm<-rpart(V11~.,training_set, method = "class")

p<-predict(dtm, test_set, type = "class")

confusionMatrix(test_set[,11], p)
#accuracy 0.9298

# ## Random Subsampling, 75% split
acc<-c()
set.seed(3333)
for (i in 1:10){
  split<-sample.split(df$V11, SplitRatio = 0.75)
  training_set<-subset(df, split==TRUE)
  test_set<-subset(df, split==FALSE)
  
  dtm <-rpart(V11~.,training_set,method = "class")
  p<-predict(dtm,test_set,type="class")
  dti<-confusionMatrix(test_set[,11],p)
  acc<-c(acc,dti$overall['Accuracy'])
}
cat("Average of accuracy: ",mean(acc))  #average of accuracy

# ## Random Subsampling, 66.6% split
acc<-c()
set.seed(4444)
for (i in 1:10){
  split<-sample.split(df$V11, SplitRatio = 0.666)
  training_set<-subset(df, split==TRUE)
  test_set<-subset(df, split==FALSE)
  dtm <-rpart(V11~.,training_set,method = "class")
  p<-predict(dtm,test_set,type="class")
  dti<-confusionMatrix(test_set[,11],p)
  acc<-c(acc,dti$overall['Accuracy'])
}
cat("Average of accuracy: ",mean(acc))  #average of accuracy


## Cross validation
#75%
set.seed(5555)
split<-sample.split(df$V11, SplitRatio = 0.75)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-train(V11~., data = training_set, method='rpart', trControl = trainControl(method = 'cv', number = 10))

p<-predict(model, test_set, method='class')

confusionMatrix(test_set[,11], p)

#66.6%
set.seed(6666)
split<-sample.split(df$V11, SplitRatio = 0.666)
training_set<-subset(df, split==TRUE)
test_set<-subset(df, split==FALSE)

model<-train(V11~., data = training_set, method='rpart', trControl = trainControl(method = 'cv', number = 10))

p<-predict(model, test_set, method='class')

confusionMatrix(test_set[,11], p)
