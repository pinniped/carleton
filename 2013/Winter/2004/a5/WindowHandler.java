import java.awt.event.*;
public class WindowHandler implements WindowListener{
	private CloseableFrame f;
	public WindowHandler(CloseableFrame f) {
		this.f = f;
		f.addWindowListener(this);
	}
	public void windowActivated(WindowEvent e) {}
	public void windowClosing(WindowEvent e) {
		System.out.println("TEST");
		f.dispose();
		System.exit(0);
	}
	public void windowDeactivated(WindowEvent e) {}
	public void windowClosed(WindowEvent e) {}
	public void windowDeiconified(WindowEvent e) {}
	public void windowIconified(WindowEvent e) {}
	public void windowOpened(WindowEvent e) {}
}
