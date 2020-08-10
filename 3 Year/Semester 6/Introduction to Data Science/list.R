#q1 
p <- c(2,7,8)
q <- c("A", "B", "C")
x<-list(p,q)
x[2]
# "A" "B" "C"

#q2

w <- c(2, 7, 8)
v <- c("A", "B", "C")
x <- list(w, v)

x[[2]][1]<-"K"


#q3
a <- list ("x"=5, "y"=10, "z"=15)
sum(unlist(a))

#q4
Newlist <- list(a=1:10, b="Good morning", c="Hi")
Newlist$a <- Newlist$a + 1
Newlist

#q5
b <- list(a=1:10, c="Hello", d="AA")
b$a[-c(2)]

#alternate approach
b$a[c(1,3:10)]

#q6
x <- list(a=5:10, c="Hello", d="AA")
x$z<-"NewItem"

#q7
y <- list("a", "b", "c")
names(y)<-c("one", "two", "three")

#q8
x <- list(y=1:10, t="Hello", f="TT", r=5:20)
length(x$r)

#q9
string <- "Grand Opening"
v<-as.list(unlist(strsplit(string, "\\s+")))

#q10
y <- list("a", "b", "c")
q <- list("A", "B", "C", "a", "b", "c")
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

length(unlist(z$x))
length(unlist(z$y))

z[[1]][[2]][3]#g


z[[2]][[2]][5]

#q12
y <- list("a", "b", "c")
q <- list("A", "B", "C", "a", "b", "c")
y1<-unlist(y)
q1<-unlist(q)

(ans<-as.list(q1[q1 != y1]))

#alternate approach
(setdiff(q, y))
