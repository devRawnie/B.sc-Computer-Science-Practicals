


deck<-list(face=c(1:10,"J","Q","K"),suit=c("Heart","Spade","Diamond","Club"), value=c(1:13)) 
x=c("1",2:4)
y=1:8
z=c("a","b","c")

cards<-data.frame(val2=x,val3=z)  #
#can't be dataframe
cards[[2]][2]
length(cards)
cards$fac
cards2<-c(cards,brand=c("brand1","b2"))
cards

cards$nullcomp<-NULL
cards[sapply(cards,is.null)]<-NULL
cards<-unlist(cards)

hand<-data.frame(face=c(1,"J","K",3),suit=c("Heart","Diamond","Club","Club"), value=c(1,11,13,3))
hand<-data.frame(face=c(1,"J","K",3),suit=c("Heart","Diamond","Club","Club"), value=c(1,11,13,3),stringsAsFactors = FALSE)
class(hand$suit)
hand$suit[3]<-"spade"
typeof(hand)
class(hand)
str(hand)
hand[2,c(1,2)]

search() #.GlobalEnv is the workspace.
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
attach(hand)
hand
hand$suit[3]<-"Spade" #If factor, then error and assigns NA
hand$suit[2]<-"Club"
hand
suit
detach() #detaches last attached
attach(hand)
suit

attach(hand) #Don't do this
search()
ls(2)
ls(3)

hand2<-data.frame(face=c(2,"Q",10,1),suit=c("Heart","Heart","Club","Spade"), value=c(2,12,10,1),stringsAsFactors = FALSE)
rbind(hand,hand2)
hand
cbind(hand,hand2)
