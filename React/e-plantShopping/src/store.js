import { configureStore } from '@reduxjs/toolkit';
import cartReducer from './CartSlice';

// Create the Redux store
export const store = configureStore({
  reducer: {
    cart: cartReducer,
  },
});
