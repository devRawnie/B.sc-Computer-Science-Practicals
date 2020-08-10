#q1
A<-matrix(c(2,0,1,3), ncol=2)
B<-matrix(c(5,2,4,-1), ncol=2)
A+B
A-B

#q2
A
3*A

#q3
diag(c(4,1,2,3))

#q4
b<-c(7,4)
dim(b)<-c(2,1)
product<-A %*% b
product

#q5
t(A)

#q6
solve(A)

#q7
x<-solve(A,b)

#q8
x<-c(1:3)
y<-c(4:6)
z<-c(7:9)
A<-cbind(x,y,z)
rownames(A)<-c("a", "b", "c")

#q9
B<-1:12
B<-matrix(B, nrow=4, byrow=TRUE)

rownames(B)<- letters[1:4]
colnames(B)<-letters[24:26]
B
B1<-matrix(B, nrow=4, byrow=FALSE)

#q10
subB<-B[2:4, ]

#q11
3*A

A+subB
A-subB
A+B # gives an error, as the dimensions of the two vectors do not match
