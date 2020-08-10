#q1
Age <- c(22, 25, 18, 20)
Name <- c("James", "Mathew", "Olivia", "Stella")
Gender <- c("M", "M", "F", "F")
df<-data.frame(Age, Name, Gender)
df_1<-df[1:2,]

#q2
df2<-df[,c(2,1,3)]
df2

#q3
df3<-df[,c(3,1,2)]
df3

#q4
df4<-df
df4$Age<-NULL

#q5
df5<-df

names(df5)[names(df5)=="Name"]<-"Firstname"
df5


#q6
sorted_df<-df[order(df$Age,decreasing = TRUE), ]
sorted_df[which.min(sorted_df$Age), ]


#q7
numeric_rows<-(iris[sapply(iris, is.numeric)])

#q8
print("Mean Sepal.Length", quote = FALSE)
print(tapply(iris$Sepal.Length,iris$Species, mean))  
print("Mean Sepal.Width", quote = FALSE)
print(tapply(iris$Sepal.Width,iris$Species, mean))  
print("Mean Petal.Length", quote = FALSE)
print(tapply(iris$Petal.Length,iris$Species, mean))  
print("Mean Petal.Width", quote = FALSE)
print(tapply(iris$Petal.Width,iris$Species, mean))  

#Better way
species.wise.mean<- apply(iris[,1:4], 2, function(x) tapply(x, iris$Species, mean))
print(species.wise.mean)

#q17

q17<-sapply(numeric_rows, function(x) tapply(x, iris$Species, mean))
write.csv2(q17, "q17.csv", row.names = FALSE)

#q18
# is.even<-function(x){
#     if(is.na(x)){
#       return(NA)
#     }
#     else if((x %% 2) == 0){
#     return(TRUE)
#   }else{
#     return(FALSE) 
#   }
# }
# 
# q18<-function(x){
#   x[!is.finite(x)]<-NA
#   output<-sapply(x, is.even)
#   return(output)
# }

# temp<-c(1,0,0,1,1,Inf, Inf, NaN, NA, NA, 1,1)
# print(q18(temp))


#q22
#install.packages(c("reshape", "reshape2"))
library(reshape2)

iris
melted.iris<-melt(df, id.vars = "Species")
melted.iris
casted.iris<-cast(melted.iris)
casted.iris  
