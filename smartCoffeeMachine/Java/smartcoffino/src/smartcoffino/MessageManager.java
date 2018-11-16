package smartcoffino;

import javafx.application.Platform;
import modulo_lab_2_2.msg.jssc.*;

public class MessageManager implements Runnable {
	private CommChannel channel;
	private Gui gui;

	public MessageManager(Gui gui) {
		this.gui = gui;
	}

	@Override
	public void run() {

		try {
			channel = new SerialCommChannel("COM8", 9600);

			/* attesa necessaria per fare in modo che Arduino completi il reboot */
			System.out.println("Waiting Arduino for rebooting...");
			Thread.sleep(4000);
			System.out.println("Ready.");

			while (true) {
				int msg = Integer.parseInt(channel.receiveMsg().replaceAll(" ", "").replaceAll("\r", ""));
				if (msg > 1 && msg < 8) {
					Platform.runLater(new Runnable() {
						public void run() {
							gui.setSugar(msg - 2);
						}
					});
				} else {
					switch (msg) {
					case 0:
						Platform.runLater(new Runnable() {
							public void run() {
								gui.printMessage("...");
							}
						});
						break;
					case 1:
						Platform.runLater(new Runnable() {
							public void run() {
								gui.printMessage("Welcome!");
								try {
									gui.setSugar(Integer
											.parseInt(channel.receiveMsg().replaceAll(" ", "").replaceAll("\r", "")));
								} catch (NumberFormatException | InterruptedException e) {
									e.printStackTrace();
								}
							}
						});
						break;
					case 8:
						Platform.runLater(new Runnable() {
							public void run() {
								gui.printMessage("making coffee! :)");
							}
						});
						break;
					case 9:
						Platform.runLater(new Runnable() {
							public void run() {
								gui.printMessage("the coffee is ready! :D");
							}
						});
						break;
					case 10:
						Platform.runLater(new Runnable() {
							public void run() {
								gui.printMessage("no more coffee. Waiting for recharge");
								gui.maintenance();
							}
						});
						break;
					default:
						System.out.println("internal errorrrrrr");
						break;
					}
				}
				Thread.sleep(100);
			}
		} catch (Exception e) {
		}
	}

	public void send(String msg) {
		channel.sendMsg(msg);
	}

}
