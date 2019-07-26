enum Language{
JAVA(1), PYTHON(2), PEARL(3), SCALA(4);
private int rank;
Language(int a){	
rank = a;
}
public int getRank()
{
return rank;
}
}
class UseEnum{

public static void main(String args[])
{
Language ob;
for(Language a: Language.values())
{

System.out.println(a + ": " + a.getRank());

}
}

}