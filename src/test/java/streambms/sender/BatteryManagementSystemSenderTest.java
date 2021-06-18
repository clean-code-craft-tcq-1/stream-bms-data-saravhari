package streambms.sender;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import org.junit.Test;

import streambms.model.Battery;

public class BatteryManagementSystemSenderTest {

	@Test
	public void givenBatteryParametesAsNull_whenStreamingData_thenReturnNull() {
		Battery battery = null;

		assertNull(BatteryManagementSystem.sendBatteryParameters(battery));
	}

	@Test
	public void givenBatteryParametesAsValid_whenStreamingData_thenReturnBattery() {
		Battery battery = BatteryManagementSystem.getBatteryParameters();

		assertNotNull(BatteryManagementSystem.sendBatteryParameters(battery));
	}

}
