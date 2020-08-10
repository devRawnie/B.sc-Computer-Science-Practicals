#Apriori Algorithm
#package -> arules
# install.packages("arules", dependency=TRUE)
# install.packages("arulesViz", dependencies = TRUE)
library(arules)
data(Groceries)

summary(Groceries)
class(Groceries)
#class: transactions

itemFrequencyPlot(Groceries, topN=5)
#item frequency plot
# str(Groceries)
## Support =  50%, Confidence = 75%
rules<- apriori(Groceries, parameter = list(supp=0.8, conf=1))
# rules<- apriori(Groceries, parameter = list(supp=0.001, conf=0.5))

inspect(rules)

rules<-sort(rules, by="confidence", decreasing = TRUE)

inspect(rules[1:10])

plot(rules[1:10])

#install.packages("arulesViz", dependencies = TRUE)
library(arulesViz)

plot(rules)

#install.packages("caTools")
#library(caTools)

#top 10 rules
plot(rules[1:20], method="graph", control = list(type = "items"))

#parallel coordinates
plot(rules[1:20], method="paracoord", control = list(reorder = TRUE))


#matric antecedents

#plot(rules[1:20], method ="matrix", control=list(reorder = TRUE))
plot(rules[1:20], method ="matrix")


plot(rules[1:20], method="grouped")


## Support = Confidence = 60%
# rules<- apriori(Groceries, parameter = list(supp=0.6, conf=0.6))
inspect(rules[1:10])

rules<-sort(rules, by="confidence", decreasing = TRUE)

inspect(rules[1:10])

plot(rules[1:10])

#install.packages("caTools")
#library(caTools)

#top 10 rules
plot(rules[1:10], method="graph", control = list(type = "items"))

plot(rules[1:10], method="paracoord", control = list(reorder = TRUE))

plot(rules[1:10], method ="matrix")

plot(rules[1:10], method="grouped")
