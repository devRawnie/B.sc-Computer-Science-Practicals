stats<-function(ob){
  # Mean
  mean_radii<-mean(ob[1,])
  mean_circum<-mean(ob[2,])
  # Median
  median_radii<-median(ob[1,])
  median_circum<-median(ob[2,])
  # Mode
  uniqv<-unique(ob[1,])
  mode_radii<-uniqv[which.max(tabulate(match(ob[1,], uniqv)))]
  uniqv<-unique(ob[2,])
  mode_circum<-uniqv[which.max(tabulate(match(ob[2,], uniqv)))]
  # quartile
  q_radii<-quantile(ob[1,],1/3)
  q_circum<-quantile(ob[2,],1/3)
  
  # range
  range_radii<-range(ob[1,])
  range_circum<-range(ob[2,])
  result<-data.frame(
    radii<-c(mean_radii,median_radii,mode_radii,q_radii,range_radii),
    circumference<-c(mean_circum,median_circum,mode_circum,q_circum,range_circum),
    row.names = c("Mean","Median","Mode","1/3 Quantile", "Range-Lower","Range-Upper")
    )
   colnames(result)<-c("Radii","Circumference")
   return(result)
}
stats(mat)
