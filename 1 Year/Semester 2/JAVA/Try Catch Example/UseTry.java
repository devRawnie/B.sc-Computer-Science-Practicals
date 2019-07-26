
class UseTry{
public static void main(String args[]){
int var = 5;
try{
System.out.println("Dividing "+ var + " by 0");
var = var/(var-var);
}catch(ArithmeticException e)
{

System.out.println("Inside Catch , caught Exception:   "+ e);

}

}

}