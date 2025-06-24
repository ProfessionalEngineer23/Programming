import React, { useEffect, useState } from 'react';
import { useSelector } from 'react-redux';

const SuperCoin = () => {
  const [superCoins, setSuperCoins] = useState(0);
  const cartItems = useSelector(state => state.cart.cartItems);

  const totalAmount = cartItems.reduce((total, item) => total + item.price * item.quantity, 0);

  useEffect(() => {
    if (totalAmount >= 100 && totalAmount < 200) {
      setSuperCoins(10);
    } else if (totalAmount >= 200 && totalAmount < 300) {
      setSuperCoins(20);
    } else if (totalAmount >= 300 && totalAmount < 400) {
      setSuperCoins(30);
    } else if (totalAmount >= 400 && totalAmount < 500) {
      setSuperCoins(40);
    } else if (totalAmount >= 500 && totalAmount < 600) {
      setSuperCoins(50);
    } else if (totalAmount >= 600 && totalAmount < 700) {
      setSuperCoins(60);
    } else if (totalAmount >= 700 && totalAmount < 800) {
      setSuperCoins(70);
    } else if (totalAmount >= 800 && totalAmount < 900) {
      setSuperCoins(80);
    } else if (totalAmount >= 900 && totalAmount < 1000) {
      setSuperCoins(90);
    } else if (totalAmount >= 1000) {
      setSuperCoins(100);
    } else {
      setSuperCoins(0);
    }
  }, [totalAmount]);

  return (
    <div className="super-coins" style={{ textAlign: 'center', marginTop: '20px' }}>
      <h2 className="super-coins-title">Super Coins</h2>
      <p className="super-coins-info">You will earn {superCoins} super coins with this purchase.</p>
    </div>
  );
};

export default SuperCoin;
