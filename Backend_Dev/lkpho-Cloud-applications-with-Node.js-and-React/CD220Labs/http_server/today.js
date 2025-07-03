// today.js
const { DateTime } = require("luxon");

module.exports.getDate = function getDate() {
    // Get the current time in Europe/Dublin timezone
    return DateTime.now().setZone("Europe/Dublin");
};
