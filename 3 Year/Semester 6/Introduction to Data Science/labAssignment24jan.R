#assignment 1

#q1
p <- c(2,7,8)
q <- c("A", "B", "C")
x<-list(p,q)
x
x[2]

#q2

w <- c(2, 7, 8)
v <- c("A", "B", "C")
x <- list(w, v)
x[[2]][1]<-"K"
x


#q3

a <- list ("x"=5, "y"=10, "z"=15)
a
sum(unlist(a))

#q4
Newlist <- list(a=1:10, b="Good morning", c="Hi")
Newlist$a <- Newlist$a + 1
Newlist


#q5
b <- list(a=1:10, c="Hello", d="AA")



#q6

x <- list(a=5:10, c="Hello", d="AA")
x$z<-"NewItem"
x

#q7
y <- list("a", "b", "c")
names(y)<-c("one", "two", "three")
y

#q8
x <- list(y=1:10, t="Hello", f="TT", r=5:20)
length(x$r)

#q9
string <- "Grand Opening"
v<-as.list(unlist(strsplit(string, "\\s+")))
v

#q10
y <- list("a", "b", "c")
q <- list("A", "B", "C", "a", "b", "c")
y1<-unlist(y)
q1<-unlist(q)
y1
(ans<-as.list(q1[q1 != y1]))
y
q
z<-setdiff(q,y)
z
#q11
A=letters[1:4]
B=letters[5:10]
C=letters[11:15]
D=c(1:10)
E=c(20:5)
x<-list(A=A, B=B, C=C)
y<-list(D=D, E=E)
z<-list(x=x, y=y)
#part 1
length(z$x)
length(z$y)
length(unlist(z$y))

z[[1]][[2]][3]#g
z[[1]][[3]]
z[[2]][[2]][5]

#q12
y <- list("a", "b", "c")
q <- list("A", "B", "C", "a", "b", "c")
y1<-unlist(y)
q1<-unlist(q)
y1
(ans<-as.list(q1[q1 != y1]))


#matrix dimensions renaming

z<-1:30
dim(z)<-c(2,3,5)
dimnames(z)<-list(
  c("r1", "r2"),
  c("c1", "c2", "c3"),
  c("s1","s2","s3","s4","s5" )
)
z

z<-1:30
dim(z)<-c(5,6)
dimnames(z)<-list(
  c("r1", "r2", "r3","r4", "r5"),
  c("r1", "r2", "r3","r4", "r5", "r6")
)
z


#apply(v, FUN = length)









#dataframe assignment
#q1
Age <- c(22, 25, 18, 20)
Name <- c("James", "Mathew", "Olivia", "Stella")
Gender <- c("M", "M", "F", "F")
df<-data.frame(Age, Name, Gender)
df_1<-df[1:2,]


#q7
numeric_rows<-(iris[sapply(iris, is.numeric)])
class(numeric_rows)

?data.frame

#q2

df3<-df[,c(2,1,3)]
df3

#q3
df2<-df[,c(3,1,2)]
df2

#q4

df3<-df[, 2:3]
df3

#q5
df4<-df

names(df4)[names(df4)=="Name"]<-"First Name"
df4
#q6
sorted_df<-df[order(df$Age,decreasing = TRUE), ]


#q8
iris
names<-c("setosa", "versicolor", "virginica")

iris_mean<-tapply(iris$Sepal.Length, iris$Species,  mean)
summary(iris)
iris_mean


#method for finding mode