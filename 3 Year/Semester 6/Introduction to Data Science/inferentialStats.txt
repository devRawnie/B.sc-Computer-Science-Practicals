#q23
set.seed(1234)
findZ<-function(x){
  return((x - 80)/15)
}
n<-rnorm(5000,mean = 80, sd = 15)
zvalues<-sapply(n, findZ)
df<-data.frame(points=n, zscore=zvalues)

t.test(n, mu=85, conf.level = 0.97)
##p value is 2.2 * 10^-16 which is very less than the 5% level. Hence the true mean is not 85(Which is obvious as we set the mean equal to 80 ourself)

#q24
set.seed(2345)
prop.test(x=25145, n = 49152, p = 0.5)
##p value is 2.9 * 10^-7 which is very less than the 5% significance level. Hence the null hypothesis that the dice was unbiased is false

#25
# Null Hypothesis H0
# : mu = 3.25 cm (the sample has been drawn from the
#                population mean mu = 3.25 cm and SD  = 2.61 cm)
# Alternative Hypothesis H1
# : mu ≠ 3.25 cm (two tail) i.e., the sample has not been
# drawn from the population mean mu = 3.25 cm and SD  = 2.61 cm.
# Consider The level of significance alpha = = 5% i.e  .05

#test Statisics: Mean Population - Mean Sample / (SD_Population)/(N)^1/2
z_cal <- (3.4-3.25)/(2.61/sqrt(900))
z_cal
#At 5% significance level, Z-Score corresponds to 1.96,
#and z_cal<1.96 i.e 1.724138<1.96
#Inference: Hence the null hypothesis is accepted.
#I.E. Data has been drawn from the population mean m = 3.25 cm and SD, s = 2.61 cm.

#25 #part 2
#95% confidence (1.96) limits for the population mean mu are :
Std_err <- 2.61/sqrt(900)
lower_lim_95 <-3.4-(1.96 * Std_err)
upper_lim_95<-3.4+(1.96 * Std_err)
#3.229≤mu≤ 3.571

##98% confidence (2.33) limits for the population mean mu are :
lower_lim_98 <-3.4-(2.33 * Std_err)
upper_lim_98<-3.4+(2.33 * Std_err)
#3.197≤mu≤ 3.603




#26  ##if count of male/female workers (in total) is larger then count of skilled workers of the corresponding sex should also be larger
df_village <- data.frame(Skilled=c(40,10,50),Unskilled=c(20,30,50),Total=c(60,40,100),row.names = c("Male","Female","Total")) 
##Null Hypothesis H0:
#  The nature of work and sex are independent of each other.
##Alternate Hypothesis H1:
#  The nature Of Work is dependent of sex.
# Consider The level of significance alpha = = 5.0 % i.e .05
xsq<-chisq.test(df_village)

#Since the significant value of z=1.96 and alpha =0.05
#and p = 0.002243
#Inference: :Since the calculated value of p < alpha i.e 0.00243 < 0.05 hence
#The null hypothesis is rejected at 95% confidence limit.
## Hence, the nature Of Work is dependent of sex.