package streambms;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import streambms.constant.BatteryFactor;
import streambms.model.Battery;

public class BatteryManagementSystem {

	public static Battery sendBatteryParameters(Battery battery) {
		if (battery == null)
			return null;

		return battery;
	}

	public static Battery getBatteryParameters() {
		float temperature = getRandomNumber(BatteryFactor.MIN_TEMPERATURE, BatteryFactor.MAX_TEMPERATURE);
		float soc = getRandomNumber(BatteryFactor.MIN_SOC, BatteryFactor.MAX_SOC);
		float chargeRate = getRandomNumber(BatteryFactor.MIN_CHANGE_RATE, BatteryFactor.MAX_CHANGE_RATE);

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
		} catch (JsonProcessingException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public static float getRandomNumber(float min, float max) {
		float rounded = Math.round(((Math.random() * (max - min)) + min) * 100);
		return (float) (rounded / 100.0);
	}

}
