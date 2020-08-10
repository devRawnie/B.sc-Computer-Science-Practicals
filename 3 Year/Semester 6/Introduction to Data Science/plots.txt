#q15
# install.packages('ggpubr')
library(ggplot2)
library(ggpubr)
# plot(sample40, xlab="Frequency Distribution", ylab = "Faces of Die", type = "b")
# df40<- data.frame(table(sample40))
# ggplot(df40, aes(x=Freq, y=sample40)) + geom_point(color= "blue",size=3)
# 
sample40<-sample(1:6, 40, replace = TRUE)
df40<- data.frame(table(sample40))
df40$Freq<- df40$Freq / 40
plot40<-ggplot(df40, aes(x=sample40, y=Freq)) + geom_point(aes(color=sample40), show.legend = F)
rm(sample40)

sample70<-sample(1:6, 70, replace = TRUE)
df70<- data.frame(table(sample70))
df70$Freq<- df70$Freq / 70
plot70<-ggplot(df70, aes(x=sample70, y=Freq)) + geom_point(aes(color=sample70), show.legend = F)
rm(sample70)

sample100<-sample(1:6, 100, replace = TRUE)
df100<- data.frame(table(sample100))
df100$Freq<- df100$Freq / 100
plot100<-ggplot(df100, aes(x=sample100, y=Freq)) + geom_point(aes(color=sample100), show.legend = F)
rm(sample100)

sample5000<-sample(1:6, 5000, replace = TRUE)
df5000<- data.frame(table(sample5000))
df5000$Freq<- df5000$Freq / 5000
plot5000<-ggplot(df5000, aes(x=sample5000, y=Freq)) + geom_point(aes(color=sample5000), show.legend = F)
rm(sample5000)

ggarrange(plot40, plot70, plot100, plot5000, ncol = 2, nrow=2)

#q16

plot40<-ggplot(data =  df40,mapping = aes(x=sample40,y=Freq, fill=sample40)) + geom_bar(stat = "identity", show.legend = F)
plot70<-ggplot(data =  df70,mapping = aes(x=sample70,y=Freq, fill=sample70)) + geom_bar(stat = "identity", show.legend = F)
plot100<-ggplot(data =  df100,mapping = aes(x=sample100,y=Freq, fill=sample100)) + geom_bar(stat = "identity", show.legend = F)
plot5000<-ggplot(data =  df5000,mapping = aes(x=sample5000,y=Freq, fill=sample5000)) + geom_bar(stat = "identity", show.legend = F)

ggarrange(plot40, plot70, plot100, plot5000, ncol = 2, nrow=2)


dev.off()
rm(list=ls())

##Assignment q3
#normal distribution
sample.data1k<-rnorm(1000)
norm1k<-ggplot() +
  geom_histogram(aes(sample.data1k),bins = 100, fill="red")

sample.data10k<-rnorm(10000)
norm10k<-ggplot() +
  geom_histogram(aes(sample.data10k),bins = 100, fill="red")

ggarrange(norm1k, norm10k,nrow=2)

#uniform distribution
sample.data1k<-runif(1000, min = -5, max=5)
unif1k<-ggplot() +
  geom_histogram(aes(sample.data1k),bins = 100, fill="red")

sample.data10k<-runif(10000,min = -5, max=5)
unif10k<-ggplot() +
  geom_histogram(aes(sample.data10k),bins = 100, fill="red")

ggarrange(norm1k, norm10k,nrow=2)

sample.data1k<-rbinom(1000, 20, 0.5)
binom1k<-ggplot() +
  geom_histogram(aes(sample.data1k),bins = 100, fill="red")

sample.data10k<-rbinom(10000, 20, 0.5)
binom10k<-ggplot() +
  geom_histogram(aes(sample.data10k),bins = 100, fill="red")

ggarrange(norm1k, norm10k,nrow=2)

##Conclusion: As the sample size increases, the sample tends towards normal distribution
