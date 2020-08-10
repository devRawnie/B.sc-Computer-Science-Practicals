#fileurl <- "http://raw.github.com/edwindj/datacleaning/master/data/df.csv"
#download.file(fileurl, destfile = "dirty_iris.csv",method = "curl")
df = read.csv("dirty_iris.csv")

#summary(df)
# which(is.na()) returns which row indices have na values
#(sum(is.na(df)))

#na_values<-which(is.na(df))

comp_cases<-complete.cases(df)


#na_values
#as.numeric(comp_cases)
#part 1
n_complete<-sum(comp_cases)

percent_complete<- 100*n_complete/length(comp_cases)
paste("Complete Cases in IRIS dataframe: ", percent_complete, "%")

#part2
is.na(df)<-sapply(df, is.infinite)

#part3
library(editrules)
(rules<-editfile("q2rules.txt"))

#part4
violations<- violatedEdits(rules, df)
#print(violations)

summary(violations)
plot(violations)

#part 5
sepals<-df$Sepal.Length

boxplot(sepals, horizontal = TRUE)
summary(df$Sepal.Length)


df1<-sepals[sepals > 0 & sepals < 7]
summary(df1)

boxplot(df1, horizontal=TRUE)
#boxplot(df1, horizontal=TRUE, notch = TRUE)

boxplot.stats(sepals)

     