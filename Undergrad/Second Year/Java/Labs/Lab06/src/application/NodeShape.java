package application;

import java.awt.geom.Ellipse2D;

/**
 * A class for describing the shape of a node.
 * @author Andreea Rindasu
 *
 */
public class NodeShape extends Ellipse2D.Double {

	private static final long serialVersionUID = 1L;

	// define the shape of a node
	public NodeShape(double x0, double y0, double radius) {
	        super(x0 - radius / 2, y0 - radius / 2, radius, radius);
	    }
}
