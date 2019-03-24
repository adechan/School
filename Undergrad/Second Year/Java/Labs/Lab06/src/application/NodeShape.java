package application;

import java.awt.geom.Ellipse2D;

public class NodeShape extends Ellipse2D.Double {
	   /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public NodeShape(double x0, double y0, double radius) {
	        super(x0 - radius / 2, y0 - radius / 2, radius, radius);
	    }
}
