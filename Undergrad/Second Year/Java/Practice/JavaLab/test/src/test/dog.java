package test;

public class dog {
	public String name;
	public static final String MESSAGE = "Come here, ";
	public static final String DEFAULT_BARK = "Woof!";
	
	public dog(String name)
	{
		this.name = name;
	}
	
	public void come() {
		System.out.println(MESSAGE + name + "");
		
	}

	public void bark() {
		System.out.println(DEFAULT_BARK);
		
	}
}
