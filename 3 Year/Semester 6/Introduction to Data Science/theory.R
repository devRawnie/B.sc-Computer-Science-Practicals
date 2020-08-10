#q1 which are formal arguments, free variables, local variables, global variables?
# Why doesn’t above code throw error trying to square ‘a’?  
b<-3
f<-function(x='a',y){
  x^2 + y/2
  a<-z
}
# b is a global variable, as it is defined outside the scope of any block or function, and is accessible everywhere in the file
# z is a free variable as it is not used within a function,   neither a formal parameter to the function nor defined in the function's body 
# x, y are formal arguments to the function f. Formal because they do not represent the actual values, but just a formalized container which will hold the actual value passed to it while calling it
# a is a local variable, as it is defined inside the scope of function f and is accessible only there
# The code does not give any error, due to a concept called LAZY LOADING. R will store the definition of function f and will only compile and run it when it needs to run it, i.e. when it is called. 

#q2 Give R command to v<-c(1,6,9,7,5,4) to 3x2 matrix. Write down the matrix created.
v<-c(1,6,9,7,5,4)
m<-matrix(v, nrow=3)
# m   (Column Wise filling by default)
# [,1] [,2]
# [1,]    1    6
# [2,]    9    7
# [3,]    5    4

#q3 Given the dataframe (a=c(1,2,3), b=c(4,5,6), c= c(7,8,9)). Write R commands to select the values (4,5,6)
df<-data.frame(a=c(1,2,3), b=c(4,5,6), c= c(7,8,9))
# to select 2nd column
df[,2]
df$b

#q4 Given the dataframe (a=c(1,2,3), b=c(4,5,6), c= c(7,8,9)). What is df[,3]?
df[,3]
# this returns the entire third column
# [1] 7 8 9

#q5 Given the dataframe (a=c(1,2,3), b=c(4,5,6), c= c(7,8,9)). What is df[1,]?
df[1,]
# this returns the entire first row
#   a b c
# 1 1 4 7

#q6 Give syntax for adding inline equation in Rmarkdown. 
# $______$
# This summation expression $\sum_{i=1}^n X_i$ appears inline.


# q7 Write R commands(s) to create a barplot of species –wise avg sepal.length using inbuilt iris dataset

df<-iris
avgLength<-as.data.frame(sapply(iris[,1:4], function(x) tapply(x, iris$Species, mean)))

barplot(height = avgLength$Sepal.Length, 
        names.arg=row.names(avgLength),
        xlab = "Species",
        ylab = "Average Sepal Length",
        col=c("red", "yellow", "blue"),
        width = 0.85
        )
# q8 Given that out of previous 300 coin tosses, 100 resulted in head. Give R command to test the hypothesis that probability of getting a head in next coin toss is 0.3? 
p<-prop.test(100,300,p = 0.3)
#p value is 0.231, which is greater than the 5% significance level. Hence we accept the hypothesis i.e. we can say p = 0.3 with 95% confidence

#q9 In hypothesis testing question above, what will p-value<.02 in the output for your test indicate? 
## If p value came out to be less than 0.02 which will be less than 0.05(or 5% confidence level), then we reject the null hypothesis, and conclude that there's a significant difference between actual and proposed probabilities

#q10 Give R command to combine multiple strings like “Data”, “Science”, “in” ,“R”, “Programming” as a single string “Data_Science_in_R_Programmming” ? 
paste("Data", "Science", "in", "R", "Programming", sep = "_")

#q11 What is the difference between "%%" and "%/%"? 
# %% is the modulus operator. It returns the remainder on dividing A by B.
# %/% is the division operator. It returns the result of dividing A by B, as an integer. After removing the fractional part
