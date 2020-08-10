#q19  
nthTriangular<-function(n){
  return((n*(n+1))/2);
}
n<-1:20
l<-letters[1:20]

sq<- sapply(n,nthTriangular)
df<- data.frame(sq, l)
names(df)<-c("TNo", "letter")

(vowelTriangularN <- df[df$letter %in% c("a", "e", "i", "o", "u"), ])
rm(list=ls())
#q20
rm(list=ls())
indians<- read.csv("indian_males.csv", header = TRUE, stringsAsFactors = FALSE)

fetchMiddleName<-function(n){
  ch = strsplit(n, " ")[[1]][2]
  if(isTRUE(nchar(ch) == 1)){
    ch = NA
  }
  if( isTRUE(grepl("[^a-z ]", n, ignore.case = TRUE)) ){
    ch = NA
  }
    return(ch)    
}
fetchKUMARS <- function(n){
  pattern = "^k(?:umar|r)?$"
  return(grepl(pattern, n))
}

indians$mid <- sapply(indians$name, fetchMiddleName, USE.NAMES = FALSE)
indians <- indians[complete.cases(indians), ]
kumars <- indians[sapply(indians$mid, fetchKUMARS), 1]
kumars
rm(list=ls())

#21
x <- c("Swan swam over the pond, Swim swan swim!","Swan swam back again -Well swum swan!")

sanitize<- function(n){
  w = gsub("[^a-z ]", "", n, ignore.case = TRUE)
  return(strsplit(w, " ")[[1]])
}
w <- sapply(x, sanitize, USE.NAMES = FALSE)
w
rm(list = ls())

#22
install.packages("reshape2", dependencies = TRUE)

library(reshape2)

iris
melted.iris<-melt(df, id.vars = "Species")
melted.iris
casted.iris<-cast(melted.iris)
casted.iris  

