data("iris")
plot(iris$Sepal.Length, iris$Sepal.Width)

irisScaled<- scale(iris[,-5])

#summary(irisScaled)

fitK <- kmeans(irisScaled, 3)

fitK$size
## result: 50 62 38
## as compared to original: 50 50 50
str(fitK)

plot(irisScaled, col=fitK$cluster)
# 
# k <-list () #initialize an empty list K
# for (i in 1:10) {
#   k[[i]] <- kmeans(irisScaled,i)
# }
# 
# betweenss_totss <-list()
# for (i in 1:10) {
#   betweenss_totss[[i]] <- k[[i]]$betweenss/k[[i]]$totss
# }
# plot(1:10,betweenss_totss,type = "b",ylab = "betweenss ss/total ss",xlab = "Cluster(k)")
# ## K
# 
# for (i in 1:4) {
#   plot(iris,col=k[[i]]$cluster)
# }

table(iris$Species, fitK$cluster)
library(ggplot2)
ggplot(iris, aes(Petal.Length, Petal.Width, color=Species)) + geom_point()
ggplot(iris, aes(Petal.Length, Petal.Width, color=fitK$cluster)) + geom_point()

## Heirarichal Clustering

d<- dist(irisScaled)
fitH <- hclust(d, "ward.D2")
plot(fitH)
rect.hclust(fitH,k=3,border = "red")
cluster<-cutree(fitH,3)
plot(irisScaled, col=iris$Species)
plot(irisScaled, col=cluster)
table(iris$Species, cluster)
ggplot(iris, aes(Petal.Length, Petal.Width, color = Species)) +
  geom_point(size = 2) + geom_point() +
  scale_color_manual(values = c('black', 'red', 'green'))


#Density Based clustering
install.packages("dbscan")
library(dbscan)
kNNdistplot(irisScaled, k = 3)
abline(h=0.7,col="red",lty=2)
fitD<- dbscan(irisScaled, eps = 0.7, minPts = 5)
plot(irisScaled, col=fitD$cluster)
plot(irisScaled, col=iris$Species)
table(iris$Species, fitD$cluster)
