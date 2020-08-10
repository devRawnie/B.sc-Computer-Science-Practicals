# Ans 1.
radii<-rnorm(n=100,mean=14,sd = 2.5)
# Ans 2
PIE<-round(pi,3)
circumference<- 2*PIE*radii

# Ans 3
mat<-matrix(c(radii,circumference), nrow = 2,ncol = 100,byrow = TRUE)

# Ans 4. 
stats<-function(ob){
# Mean
  mean_value<-mean(ob)
# Median
  median_value<-median(ob)
# Mode
  uniqv<- unique(ob)
  mode_value<-uniqv[which.max(tabulate(match(ob, uniqv)))]
# quartile
  q<-quantile(ob,1/3)

# range
  range_of_data<-range(ob)
  return(c(mean_value,median_value,mode_value,q,range_of_data))
}
radii_stats<-stats(mat[1,])
circumference_stats<-stats(mat[2,])

# Ans 5
plot(x=temperature, y=ozone, xlab="Temperature", ylab = "Ozone",main = "Temprature vs Ozone",type="p")

# Ans 6
x<-1:3
y<-4:6
z<-7:9
m<-matrix(c(x,y,z),nrow = 3,byrow = TRUE)
colnames(m)<-c("a","b","c")

# Ans 7
## Assuming
## H0 = True mean is 87
## H1 = True mean is 87         
test<-t.test(mat[2,],mu = 87)
test$p.value
## if p.value > 0.05, we reject the null hypothesis, that is there is a 95% chance that true mean is 87. 
## If p.value < 0.05, we can not reject the null hypothesis. Thus true mean is not equal to 87
if(test$p.value>0.05){
  paste("We reject the Null Hypothesis with 95% confidence. That is there is a 95% chance that true mean is equal to 87")
}else{
  paste("We can not reject the Null hypothesis, Hence true mean is not 87")
}
