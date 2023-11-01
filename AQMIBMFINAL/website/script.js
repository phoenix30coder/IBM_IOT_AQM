// Replace with your ThingSpeak channel ID and read API key
const channelID = '2320479';
const readAPIKey = 'NUWWKS8J4GUMC6SX';

// The field number you want to retrieve
const fieldNumber = 1;
var i ;
// ThingSpeak API URL
const apiUrl = `https://api.thingspeak.com/channels/${channelID}/feeds.json?api_key=${readAPIKey}`;

// Perform an HTTP GET request to retrieve data
function latest(){
    {fetch(apiUrl)
        .then((response) => response.json())
        .then((data) =>{
           // i = data.feeds.length-4;
           i=0;

        })
    }
}
latest();
function fetchdata()
{fetch(apiUrl)
  .then((response) => response.json())
  .then((data) => {
    const f1 = data.channel.field1;
    const f2 = data.channel.field2;
    const f3 = data.channel.field3;
    
    if (data.feeds.length > 0 && i <data.feeds.length) {
      var value1 = data.feeds[i].field1; 
      var value2 = data.feeds[i].field2; 
      var value3 = data.feeds[i].field3; // Change field1 to match your field number
      console.log(`Data from ThingSpeak:`);
      console.log(f1," ",value1);
      console.log(f2," ",value2);
      console.log(f3," ",value3);
      
      i=i+1;
      document.getElementById('data-container').innerHTML=`Temperature = ${value1} C<br> Humidity = ${value2} <br> GasLevel = ${value3}`;
      if(value1 > 50 && value2 > 50){
        document.getElementById('result').innerHTML = "<br>Very High Temperature <br> Harmful gas is leaked";
      }
      else if(value1 > 50){
        document.getElementById('result').innerHTML = "<br>Very High Temperature";
      }
      else if(value1 < 20){
        document.getElementById('result').innerHTML = "<br>Very Low Temperature";
      }
      else if(value1 < 20 && value2>100){
        document.getElementById('result').innerHTML = "<br>Very Low Temperature  <br> Harmful gas is leaked";
      }
      else if(value2>50){
        document.getElementById('result').innerHTML = " <br> Harmful gas is leaked";
      }
      else{
        document.getElementById('result').innerHTML = "<br>Normal Condition";
      }
    }
  })
  .catch((error) => {
    console.error('Error fetching data:', error);
  });
}

fetchdata();

setInterval(fetchdata,5000);