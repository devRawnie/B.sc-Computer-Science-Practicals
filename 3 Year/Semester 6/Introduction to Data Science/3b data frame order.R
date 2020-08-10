df<-data.frame("Customer"= c(1,4,5,2,3,7,88,65),"sal"=c(12,23,41,65,12,14,1,98))
(index<-order(df$sal))
(df1<-df[index,])

df1
?as.Date()
df <- data.frame(Date = c("10/9/2009", "10/15/2009"))
max(df)
df<-as.Date(df$Date, "%m/%d/%Y")
max(df)
str(df)
v<-c(NA,NA,0,1)
sum(is.na(v))
