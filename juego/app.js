const express = require('express');
const http = require('http');
const WebSocket = require('ws');

const app = express();
const server = http.createServer(app);
const wss = new WebSocket.Server({ server });
app.use(express.static('public'));

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/public/index.html');
});

wss.on('connection', (ws) => {
    console.log('Cliente WebSocket conectado');

    
    ws.on('message', (message) => {
        console.log(`Mensaje recibido del navegador: ${message}`);
    });
});

const PORT = process.env.PORT || 3002;
server.listen(PORT, () => {
    console.log(`Servidor Node.js escuchando en el puerto http://192.168.1.163:${PORT}`);
});
