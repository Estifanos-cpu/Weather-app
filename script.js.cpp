async function getWeather() {
  const city = document.getElementById('cityInput').value;
  const apiKey = 'YOUR_API_KEY'; // Replace with your OpenWeather API key
  const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`);
  const data = await response.json();

  if (data.cod === 200) {
    document.getElementById('weatherResult').innerHTML = 
      `<h2>${data.name}</h2>
       <p>Temperature: ${data.main.temp}°C</p>
       <p>${data.weather[0].description}</p>`;
  } else {
    document.getElementById('weatherResult').innerHTML = `<p>City not found!</p>`;
  }
}