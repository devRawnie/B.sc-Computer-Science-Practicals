#1. Count no of NA in a vector
a<-c(1,2,3,4,NA,23, NA, 1/0, -Inf,Inf)
length(a)
a[is.na(a)]
length(a[is.na(a)])
x <- c(4,6,5,7,10,9,4,15)
y <-c(1,2)
x+y
#2. What is the value of:
  c(4,6,5,7,10,9,4,15) < 7
  
#3. Add two vectors
p<-c(3,5,6,8)
q<-c(3,3,3)
p+q
#4.Output of R statements:
z<-0:9
digits <- as.character(z)
digits<-as.integer(digits)  
  
#5.Value of k for:
x <- c(1,2,3,0)
y<-(x+2)
y[(!is.na(x)) & x > 0] -> k
#6. Value of sum(x[y]):
x<-c(2,4,6,8)
y<-c(TRUE, FALSE, TRUE, TRUE)
sum(x[y])
sum(x+y)
x[y]

#######################
#####15-Jan-2020#######
#######################
#q1 Add and subtract matrices
A<-matrix(c(2,0,1,3), ncol=2)
B<-matrix(c(5,2,4,-1), ncol=2)
A+B
A-B
#q2 scalar multiplication
A
a3<-3*A
a3
#q3 diagonal matrix
mat<-diag(c(4,1,2,3), 4)
mat
#q4 matrix multiplication
b<-c(7,4)
dim(b)<-c(2,1)
product<-A %*% b
product
#q5 A transpose
t(A)
# determinant
det(A)
#q6 inverse
inv<-solve(A)
inv
#q7 solve for x
x<-inv %*% b
X<-solve(A,b)
X
#q8
x<-c(1:3)
y<-c(4:6)
z<-c(7:9)
A<-cbind(x,y,z)
A
rownames(A)<-c("a", "b", "c")

#q9
B<-1:12
B<-matrix(B, nrow=4, byrow=TRUE)
B

rownames(B)<-c("a", "b", "c", "d")
colnames(B)<-c("x", "y", "z")


#q10

subB<-B[2:4, ]
subB
#q11

3*A

A+subB
A-subB
A+B
