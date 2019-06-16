package locations;

public abstract class Node {

	protected String name;
	protected float longitude;
	protected float latitude;
	
	public Node(String name)
	{
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	public float getLongitude() {
		return longitude;
	}
	public float getLatitude() {
		return latitude;
	}
	
	@Override
	public String toString()
	{
		return getName();
	}
	
}
