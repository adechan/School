package commands;

import graphs.Graph;

public abstract class GenericCommand {

	public abstract void add(Graph graphItem);
	public abstract void list();
	public abstract void open(String name);
	public abstract void save(String filename);
	public abstract void load(String filename);
}
