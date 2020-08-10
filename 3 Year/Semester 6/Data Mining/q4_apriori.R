# 1000, 5000, 20000, 75000
val<-20000
dataset_name <- sprintf("apriori_datasets/%s/%si.csv", val, val)
reciept_df<- read.csv(dataset_name, header = FALSE)
colnames(reciept_df)<-c("Reciept_number","Food", "Quantity")

df<-reciept_df


summary(df)

head(df)

l<-1:5
food<-c("Milk", "Sugar", "Choco", "Apples", "Curd")
factor_names<-data.frame(l, food)

df$Food <- factor_names$food[match(reciept_df$Food, factor_names$l)]
rm(l,food, factor_names)
head(df)

df_t<- as(split(df$Food, df$Reciept_number),"transactions")
summary(df_t)

library(arules)
## what does the 0.001 value represent in terms of percentage

rules<- apriori(df_t, parameter = list(supp=0.001, conf  = 0.001))
#rules<- apriori(df_t)
inspect(rules)
plot(rules)

itemFrequencyPlot(df_t)
