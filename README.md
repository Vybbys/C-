# C++
<!DOCTYPE html>

<html>

<head>

  <title>Gra w kółko i krzyżyk</title>

  <link rel="stylesheet" type="text/css" href="styles.css">

</head>

<body>

  <h1>Gra w kółko i krzyżyk</h1>

  <div class="board">

    <div class="cell" onclick="makeMove(0, 0)"></div>

    <div class="cell" onclick="makeMove(0, 1)"></div>

    <div class="cell" onclick="makeMove(0, 2)"></div>

    <div class="cell" onclick="makeMove(1, 0)"></div>

    <div class="cell" onclick="makeMove(1, 1)"></div>

    <div class="cell" onclick="makeMove(1, 2)"></div>

    <div class="cell" onclick="makeMove(2, 0)"></div>

    <div class="cell" onclick="makeMove(2, 1)"></div>

    <div class="cell" onclick="makeMove(2, 2)"></div>

  </div>

  <script src="script.js"></script>

</body>

</html>

.board {

  display: grid;

  grid-template-columns: repeat(3, 1fr);

  grid-gap: 10px;

  max-width: 300px;

  margin: 0 auto;

}

.cell {

  width: 100px;

  height: 100px;

  border: 1px solid black;

  display: flex;

  align-items: center;

  justify-content: center;

  font-size: 2em;

  cursor: pointer;

}

let board = [

  ['', '', ''],

  ['', '', ''],

  ['', '', '']

];

let currentPlayer = 'X';

function makeMove(row, col) {

  if (board[row][col] === '') {

    board[row][col] = currentPlayer;

    document.getElementsByClassName('cell')[row * 3 + col].innerText = currentPlayer;

    if (checkWin()) {

      alert('Gracz ' + currentPlayer + ' wygrywa!');

      resetBoard();

    } else if (checkTie()) {

      alert('Remis!');

      resetBoard();

    } else {

      currentPlayer = currentPlayer === 'X' ? 'O' : 'X';

    }

  }

}

function checkWin() {

  // Sprawdzanie wierszy

  for (let i = 0; i < 3; i++) {

    if (board[i][0] === currentPlayer && board[i][1] === currentPlayer && board[i][2] === currentPlayer) {

      return true;

    }

  }

  // Sprawdzanie kolumn

  for (let j = 0; j < 3; j++) {

    if (board[0][j] === currentPlayer && board[1][j] === currentPlayer && board[2][j] === currentPlayer) {

      return true;

    }

  }

  // Sprawdzanie przekątnych

  if (board[0][0] === currentPlayer && board[1][1] === currentPlayer && board[2][2] === currentPlayer) {

    return true;

  }

  if (board[0][2] === currentPlayer && board[1][1] === currentPlayer  && board[2][0] === currentPlayer) {

    return true;

  }

  return false;

}

function checkTie() {

  for (let i = 0; i < 3; i++) {

    for (let j = 0; j < 3; j++) {

      if (board[i][j] === '') {

        return false; // Znaleziono puste pole, gra nie jest w remisie

      }

    }

  }

  return true; // Wszystkie pola są wypełnione, gra w remisie

}

function resetBoard() {

  board = [

    ['', '', ''],

    ['', '', ''],

    ['', '', '']

  ];

  

  currentPlayer = 'X';

  

  const cells = document.getElementsByClassName('cell');

  for (let i = 0; i < cells.length; i++) {

    cells[i].innerText = '';

  }

}
