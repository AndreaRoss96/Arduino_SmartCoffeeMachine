package smartcoffino;

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
				System.out.println(channel.receiveMsg());
				Integer msg = Integer.parseInt(channel.receiveMsg().replaceAll(" ", "").replaceAll("\n", ""));
				if (msg > 1 && msg < 8) {
					System.out.println("" + (msg - 2));
					// sugarValue=msg-2;
				} else {
					switch (msg) {

					case 1:
						gui.printMessage("Welcome!");
						break;
					case 8:
						gui.printMessage("making coffee! :)");
						// making();
						break;
					case 9:
						gui.printMessage("the coffee is ready! :D");
						// finish();
						break;
					case 10:
						gui.printMessage("no more coffee. Waiting for recharge");
						// maintenance();
						break;
					default:
						gui.printMessage("internal errorrrrrr");
						break;
					}
				}
				Thread.sleep(100);
			}
		} catch (Exception e) {
			System.out.println("Dio piemontese");
			e.printStackTrace();
		}
	}
	
	public void send(String msg) {
		channel.sendMsg(msg);
	}
	

}
