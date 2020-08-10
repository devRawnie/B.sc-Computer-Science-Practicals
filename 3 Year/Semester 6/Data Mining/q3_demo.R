install.packages("caret")
library("caret")
??caret
df<-data.frame(a=c(1,2,3,4,5), b=c(6,7,8,9,10))

summary(df)

#mean(df$a)
#sd(df$a)

df1<-df

#center works for mean
#scale works for standard deviaton
pdf1<-preProcess(df1, method = c("center") )

meandf1<-predict(pdf1, df1)
summary(meandf1)

pdf1<-preProcess(df1, method=c("scale"))
stddf1<-predict(pdf1, df1)
sd(stddf1$b)


pdf1<-preProcess(df1, method = c("center", "scale"))
combined<-predict(pdf1, df1)
sd(combined$a)
