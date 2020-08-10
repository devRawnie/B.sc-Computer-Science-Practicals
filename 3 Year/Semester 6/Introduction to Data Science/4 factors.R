rm(list=ls())

e=c("e1","e2","e3","e4","e5","e6","e77","e8")
d=c("del","mum","BLR","del","mum","del","del","BLR")
locf<-factor(d,levels=c("del","mum","BLR","P"))
locf
tapply(d,d,length) #frequency table
#or
table(d)
z<-split(e,d)
z
incomes <- c(60, 49, 40, 61, 64, 60, 59, 54)
#Find sample mean for each location
locmeans<-tapply(incomes, d, mean)
locmeans
print(locmeans)

#modal income
f=function(inputvector){t<-table(incomes); #builds contingency table of counts at each combination of factor level
mode<-names(t[max(t)])}

mode<-f(incomes)

#two factors for two way table of frequencies
table(incomes,d)
