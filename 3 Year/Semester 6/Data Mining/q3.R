library(caret)
iris_df<-iris
iris_practice<-iris_df

summary(iris)
sapply(iris_df, sd)
model1<-preProcess(iris_df, method=c("center", "scale"))

normalizedIris<-predict(model1, iris_practice)

summary(normalizedIris)
sapply(normalizedIris, sd)

winedf<-read.csv("wine.csv", header = TRUE)
winePractice<-winedf

model2<-preProcess(winedf, method=c("center", "scale"))

normalizedWine<-predict(model2, winePractice)
summary(normalizedWine)
sapply(normalizedWine, sd)
