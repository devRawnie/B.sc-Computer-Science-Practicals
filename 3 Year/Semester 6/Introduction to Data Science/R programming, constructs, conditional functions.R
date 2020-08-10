#q3 print the sum of numbers upto n ( input n)
n <- as.integer(readline(prompt="Enter any number: "))
cat("Sum of numbers from 1 to ", n, "is:", sum(1:n), fill=TRUE)

#q4 print a multiplication table for numbers upto 12
num<-as.integer(readline(prompt = "Enter any number: "))
for(j in 1:12){
  cat(num,"*",j,"=",num*j,"\n")
}

#q5 print max element in a list
getlargest<-function(x){
  return(max(unlist(x)))
}
ls<-list(1,2,3, 100, 102, 101)
print(getlargest(ls))

#q6 Compute the running total
ls<-list(10:20)
ls1<-unlist(ls)
ls1_length<-length(ls1)
runningTotal<-integer(ls1_length)
runningTotal[1]<-ls1[1]
for(i in 2:ls1_length){
  runningTotal[i]<-runningTotal[i-1] + ls1[i]
}

for(i in 0:ls1_length){
  if(i==0){
    cat("List", "Running Total\n", sep = "  ")
    } 
  else{
    cat(ls1[i], runningTotal[i],"\n",sep = "     ")  
  } 
}


#q8
linearSearch<-function(a, ls){
  n<-1
  for(x in ls){
    if(a == x){
      cat("Element found at pos: ", n)
      break
    }
    n<-n+1
  }
  if(n > length(ls))  print("Element not found", quote = FALSE)
}
v<-5:20
linearSearch(5,v)

#q9
bs<-function(i, j, a, ls){
  if(i > j){
    return(-1)
  }
  mid = (i + j) %/% 2
  if(ls[mid] == a){
    return(mid)
  }
  if(a < ls[mid]){
    j = mid-1
  }
  else if( a > ls[mid]){
    i = mid + 1
  }
  bs(i, j, a, ls)
}
binarySearch<-function(a, ls){
  ls<-sort(ls)
  pos<-bs(1, length(ls), a, ls)  
  if(pos == -1){
    print("Element not found", quote = FALSE)
  }else{
    cat("Element found at position: " , pos)
  }
  }
binarySearch(5, 4:7)


#q18
evaluate<-function(x){
  if(!is.finite(x)){
    return(NA)
  }
  if(x %% 2 == 0){
    return(TRUE)
  }else{
    return(FALSE)
  }
}

q18<-function(ls){
  return(sapply(ls, evaluate))
}
q18(c(0:10, NA, Inf, Inf, NaN,0,50:60))
