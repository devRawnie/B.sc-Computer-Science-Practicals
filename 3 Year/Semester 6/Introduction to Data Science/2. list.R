rm(list=ls())

deck<-list(face=c(1:10,"J","Q","K"),suit=c("Heart","Spade","Diamond","Club"), value=c(1:13)) 
(person<-list(name="Fred",wife="Mary",number="H38"))
deck[1]

lst<-c(deck,person)
lst
list1<-list(d=deck,p=person)
list1

key2<-"wife"
person$name
person$wife

person$nu

person$key2
person[[key2]]
person[["wife"]]
person$wife

length(deck)

lst<-list(name="Fred",NULL,wife="Mary",son="John")
lst

lst$wife<-NULL

lst

lst$NULL<-NULL  #Error
is.null(lst)
sapply(lst,is.null)
lst[sapply(lst,is.null)]<-NULL


marks<-list(algo=c(40,69,89,75),micro=c(80,84),datasc=c(90,95,79),bio=c(60,25))

marks[sapply(marks,mean)<50]<-NULL
marks


#------------------------------------------
lst
lst1<-cbind(lst,marks)  #warning, recycles
lst1

lst1<-rbind(lst,marks) #warning recycles
lst1
length(lst1)

nrow(lst1)

