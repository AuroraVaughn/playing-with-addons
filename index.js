
const addon = require('./build/Release/addon');

addon.sendTimeEvent((event) => {
  const time = event.time;
  console.log(`Time: ${time}`);
});


// keeping the event loop open
setInterval(() => {
  console.log('Keeping the event loop active...');
}, 10000);