package streambms.sender;

import com.fasterxml.jackson.databind.ObjectMapper;

import streambms.constant.BatteryFactor;
import streambms.model.Battery;

public class BatteryManagementSystem {

	private static BatteryFactor batteryFactor = new BatteryFactor();

	public static Battery sendBatteryParameters(Battery battery) {
		if (battery == null)
			return null;

		return battery;
	}

	public static Battery getBatteryParameters() {
		float temperature = getRandomNumber(batteryFactor.MIN_TEMPERATURE, batteryFactor.MAX_TEMPERATURE);
		float soc = getRandomNumber(batteryFactor.MIN_SOC, batteryFactor.MAX_SOC);
		float chargeRate = getRandomNumber(batteryFactor.MIN_CHANGE_RATE, batteryFactor.MAX_CHANGE_RATE);

		return new Battery(temperature, soc, chargeRate);
	}

	public static void sendToConsole() {
		ObjectMapper mapper = new ObjectMapper();
		String batteryData;
		try {
			for (int i = 0; i < 10; i++) {
				Thread.sleep(2000);
				batteryData = mapper.writeValueAsString(sendBatteryParameters(getBatteryParameters()));
				System.out.println(batteryData);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static float getRandomNumber(float min, float max) {
		float rounded = Math.round(((Math.random() * (max - min)) + min) * 100);
		return (float) (rounded / 100.0);
	}

}
