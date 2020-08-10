#q1 no of NA in vector
a<-c(1,2,3,4,NA,23, NA, 1/0, -Inf,Inf)
length(a[is.na(a)])

#q2
c(4,6,5,7,10,9,4,15) < 7
#Boolean vector representing "TRUE"/"FALSE" by comparing 7 with every element of the vector

#q3
p <- c (3, 5, 6, 8)
q <- c (3, 3, 3)
p+q  # gives an error as the length of the two vectors is not same

#q4
z <- 0:9
digits <- as.character(z) #converts the integer vector to character vector
as.integer(digits)      # converts the character vector to integer vector

#q5
x <- c(1,2,3,4)
(x+2)[(!is.na(x)) & x > 0] -> k
# k = 3,4,5,6

#q6
x <- c(2, 4, 6, 8)
y <- c(TRUE, TRUE, FALSE, TRUE)
sum(x[y])
