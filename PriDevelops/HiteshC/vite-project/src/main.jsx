import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'

import App from './App.jsx'
import Youtube from './Youtube.jsx'

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <App />
    <Youtube/>
  </StrictMode>,
)
