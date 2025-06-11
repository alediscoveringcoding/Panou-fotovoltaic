// Static realistic test data for a small solar panel
const data = {
    voltage: 13.2,   // Small panel in sunlight
    current: 0.55    // Current in Amps under moderate sunlight
};

const voltage = parseFloat(data.voltage);
const current = parseFloat(data.current);

const power = voltage * current;  // Power in Watts (P = V * I)
const cycleDurationMinutes = 10;  // Simulated energy cycle duration
const energyGain = power * (cycleDurationMinutes / 60);  // Energy in Wh

const formatted = {
    voltage: voltage.toFixed(2),
    current: current.toFixed(2),
    power: power.toFixed(2),
    energyGain: energyGain.toFixed(2),
    log: `Updated at ${new Date().toLocaleTimeString()}`
};

return [
    { payload: formatted.voltage },
    { payload: formatted.current },
    { payload: formatted.energyGain },
    { payload: formatted.power },
    { payload: formatted.log }
];
