#create a .txt file with the following data
#i. read the data from a file

file = read.table(file='q1.txt', header=TRUE)

#read.csv(file='q1.txt')
#editrules->Package Name, called constraints, EDITS
#install.packages('editrules')


library('editrules')

#1.editfile: write the rules in a separate file
#2.editset: write the rules in the script itself
#editset(expression(rule1, rule2))
#rule: Age >=0, Status %in% c('a', 'b', 'c')
#if(Age>=0) ageGroup == 'X'

rules = editset(expression(
  Age>=0,
  Age<=150, 
  Age>yearsmarried,
  status %in% c( 'married', 'single', 'widowed'),
  if(Age<=18) agegroup == 'child', 
  if(Age>18 && Age<=65) agegroup == 'adult', 
  if(Age>65) agegroup == 'elderly'
  ))
rules
(violations = violatedEdits(rules, file))
summary(violations)
barplot(table(violations))
plot(violations)

plot(rules, layout=layout.circle)
