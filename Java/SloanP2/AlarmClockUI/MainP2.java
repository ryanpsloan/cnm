// Ryan Sloan
// rsloan2@cnm.edu
// MainP2.java

public class MainP2
{
	private AlarmUI ui;
	public static void main(String[] args)
	{
		MainP2 app = new MainP2();
	}
	
	public MainP2()
	{
		ui = new AlarmUI();
		ui.run();
		System.exit(0);
	}
}