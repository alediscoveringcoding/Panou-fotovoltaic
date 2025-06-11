const time = msg.payload["Time"];
const zenith = msg.payload["Zenith Angle (θ_z)"];
const azimuth = msg.payload["Solar Azimuth (γ_s)"];
const incidence = msg.payload["Incidence Angle (θ)"];
const inclination = msg.payload["Surface Inclination (α)"];
const surfaceAzimuth = msg.payload["Surface Azimuth (γ)"];

msg.payload = `${azimuth},${incidence}`;
return msg;
