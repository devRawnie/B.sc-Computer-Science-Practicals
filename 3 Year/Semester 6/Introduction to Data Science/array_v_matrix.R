x<-c(1,2,3,4)
range(x)
x[-1:3]
x<-c(1,NA,-Inf,0/0)
is.nan(x)
is.na(x)
a<-c(1,2,"abc","xyz")
d<-1:4
paste(a,"pqr",d)
is.character(a)
y<-c(0,6,3,NA)
z<-x==y
z<-c(x,y,x,9)
t<-c(1,2,3)
max(x,t, na.rm = TRUE)
max(x,y, na.rm = TRUE)
pmax(x,t)
x+y
seq(1,8,along.with = x)
rep(x,times=2)
rep(x,each=2)
ls()
#rm(list=ls())

x<-c(12,13,19)
x["d"]
x>15
x[x>12]
n<-c("Ram","Shyam","Gita", "Ashok")
#both x and n must be of same length for names() method
names(x)<-n
x<-c("Ram"=12,"Shyam"=13,"Gita"=19)
x[c(1,3)]

e<-numeric(0)
length(e)<-3
attr(e,"name")

length(e)<-4
e[3]<-5
########################
###Eg1##################
z <- 1:10 
z
is.array(z)
dim(z) <- c(2, 5) 
is.array(z)
prince <-1:10
dim(prince)<-10
is.array(prince)
is.matrix(matrix)
is.matrix(z) 
z

########################
###Eg2##################
z<-1:30
dim(z)<-c(2,3,5)
is.array(z)
is.matrix(z) 
print(z)
print(z[2,3,1])
print(z[2,3])#ERROR!
print(z[,2,3]) #Correct
print(z[2,3,])
print(z[2,,1])
print(z[,,])
print(dim(z))
print(z[dim(z)])#??
print(z[c(1,2),,])
print(z[5])
print(z[c(1,2,3,4)])
attr(z,"dim")<-c(10,3)
z
attr(z,"dim")<-NULL
is.array(z)
attr(z,"dim")<-c(30)
########################
###Eg3##################
?matrix
(x <- matrix(1:10, c(5,2))) 
(y <- array(11:20, c(5,2)))
?array
identical(x, y)

########################
###Eg3##################
attributes(x) 
dim(x) <- NULL 	
print(x)

x<-1:10
dim(x)<-c(11)
#------------------------------
z<-cbind(x,y)
print(z)
(z<-rbind(x,y))
##################################
#################################
##########EXERCISE##############
##############################
##############################
x <- c(1,2,3,6,4,6,7,8,6)
length(x[x==6])
hist(x)
sum(x==6)
length(x[x>1 & x<5])
