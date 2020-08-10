dat<-data.frame(a=c(1, Inf), b = c(Inf, 3), d=c("a","b"))
which(is.na(dat))
#sapply will supply the values which are infinite and is.na() will enforce infinite values to NA
is.na(dat)<-sapply(dat, is.infinite)
dat
?which


#outliers detection
# rivers dataset, length of major north american rivers
View(rivers)
summary(rivers)
hist(rivers)
boxplot(rivers,horizontal = TRUE)

riv1<-rivers[rivers < 1250]
boxplot(riv, horizontal = TRUE)

riv2<-rivers[rivers < 1050]
hist(riv2)
boxplot(riv2, horizontal = TRUE)