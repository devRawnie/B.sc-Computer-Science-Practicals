#q11
ages<-c(20,20,20,20,20,21,21,21,22,22,22,22,23,23,23)


stats_median<-function(x){
  x<-sort(x)
  len<-length(x)
  print(x)
  print(len)
  if(len %% 2 == 0){
    return((x[len/2] + x[(len/2)+1])/2)
  }else{
    print(2)
    return(x[(len+1)/2])
  }
}

stats_mean<-function(x){
  return(sum(x)/length(x))
}
stats_mode<-function(x){
  val<-ages[max(table(x))]  
  return(val)
}
#part 1
stats_median(ages[ages < 22])

#part 2
stats_median(ages)

#part 3

stats_mean(ages)

#part 4
stats_mode(ages)

#part5-1 different approach
#new.sum<-length(ages)*stats_mean(ages) + 23*2
#(new.mean<- new.sum / (length(ages) + 2))

new.ages<-c(ages, 23, 23)
#part 1.5-1 
(new.mean<-stats_mean(new.ages))

#part 1.5-2
(new.median<-stats_median(new.ages))

#part 1.5-3
(new.mode<-stats_mode(new.ages))


#q12
d<-vector()
midpoints<-seq(95.5, 175.5, 10)
freq<-c(5,8,22,27,17,9,5,5,2)
for(i in 1:length(midpoints)){
   d<-c(d, rep(midpoints[i],freq[i]))
}

data_range<-diff(range(d))
data_variance<-var(d)
data_std<-sd(d)
data_meand<-mad(d, center = mean(d))

#q13
fdist<-function(d){
  df<-as.data.frame(table(d))
  colnames(df)<-c("Face", "Frequency")
  prob<-df[,2] / sum(df$Frequency)
  return(cbind(df, prob))  
}

sample40<-sample(1:6, 40, replace = TRUE)
sample70<-sample(1:6, 70, replace = TRUE)
sample100<-sample(1:6, 100, replace = TRUE)

fdist(sample40)
fdist(sample70)
fdist(sample100)

##inference-> As the sample size increases, the probablity reaches absolute probability that is 1/6


#interquantile deviation

iqd<-function(data, a, b){
  q<-quantile(data, c(a/(10 ^nchar(a)), b/(10 ^nchar(b))))
  return(as.numeric(abs(diff(q))))
}
iqd(sample40, 10, 60)
