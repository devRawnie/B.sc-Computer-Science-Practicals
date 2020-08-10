rm(list=ls())
x=list(v1=c(1:3),v2=c(2:4))
y=1:8
z=c("a","b","c")
cards<-data.frame(val2=x,val3=z)  
cards<-data.frame(val2=z,val3=y)
#can't be dataframe
cards
x<-1:3
cards<-data.frame(val2=x,val3=z)  

cards[[2]][3]
cards[2]
cards[[2]]

length(cards)
cards$val3


cards2<-c(cards,brand=c("brand1","b2")) #*** combining lists/dataframe using c will result in a list
                                        #however note the length here since c() flattens before concatenating
cards2
cards2<-list(cards,brand=c("brand1","b2")) #list with length=2 combines without flattening

cards$nullcomp<-NULL
cards$nullcomp
cards[sapply(cards,is.null)]<-NULL
cards<-unlist(cards)
######################################

(hand<-data.frame(face=c(1,"J","K",3),suit=c("Heart","Diamond","Club","Club"), value=c(1,11,13,3)))
hand2<-data.frame(face=c(1,"J","K",3),suit=c("Heart","Diamond","Club","Club"), value=c(1,11,13,3),stringsAsFactors = FALSE)
hand$suit[3]<-"Spade" #If factor, then error and assigns NA
hand2$suit[3]<-"Spade"
hand2

class(hand$suit)
class(hand2$suit)

typeof(hand)
class(hand)

str(hand)

hand<-hand[-2,]#delete 2nd row
#Q. Assign NA to even 'value' rows

hand
nrow(hand)
ncol(hand)


search() #.GlobalEnv is the workspace.
library(dplyr)
search()

attach(hand)
search()
ls(2) 

value<-value+1
value
hand$value
hand$value<-value
hand$value<-value-1
value
detach(hand)
rm(value)

value
attach(hand)
attach(hand2)  #masks previous available variables

detach() #detaches last attached
attach(hand)
suit

attach(hand) #Don't do this
search()
ls(2)
ls(3)

#-------------------
rm(list=ls())



(hand<-data.frame(face=c(1,"J","K",3),suit=c("Heart","Diamond","Club","Club"), value=c(1,11,13,3)))
v<-with(hand,z<-value+1)
z
v
hand$val
hand
v<-within(hand,val<-value+1)
hand


#--------------------------------------
hand2<-data.frame(face=c(2,"Q",10,1),suit=c("Heart","Heart","Club","Spade"), value=c(2,12,10,1),stringsAsFactors = FALSE)


(rbind(hand,hand2))

(cbind(hand,hand2))

hand3<-data.frame(hand,hand2)
hand3
#----------------------------------
rm(list=ls())
?sort
v<-1:9
v<-c(1,3,2)
v<-sort(v)
sort(dec=TRUE,x=v)
(-1*sort(-v))

hand2<-data.frame(face=c(2,"Q",10,1),suit=c("Heart","Heart","Club","Spade"), value=c(2,12,10,1),stringsAsFactors = FALSE)
sort(hand2$face) #alphabetical
sort(hand2$val)
hand2$value

hand2$value<-sort(hand2$value) #table is messed up
hand2
hand2<-data.frame(face=c(2,"Q",10,1),suit=c("Heart","Heart","Club","Spade"), value=c(2,12,10,1),stringsAsFactors = FALSE)

v<-order(hand2$value)
hand2[v,]
hand2<-(hand2[order(hand2$value),])
hand2

rank(hand2$value)


#find smallest
min(hand2$value)

which.min(hand2$value)

hand2[which.min(hand2$value),]

#------------------------
df<-data.frame("Customer"= c(1,4,5,2,3,7,88,65),"sal"=c(12,23,41,65,12,14,1,98))
(index<-order(df$sal))
(df1<-df[index,])
#################################
df1
?as.Date()
df <- data.frame(Date = c("10/9/2009", "10/15/2009"))
max(df)
df<-as.Date(df$Date, "%m/%d/%Y")
max(df)
str(df)
