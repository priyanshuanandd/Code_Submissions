import React from 'react'
import Carousel from '../Components/Carousel';
import Card from '../Components/Card';
function Home() {
    return (
        <>
            <Carousel></Carousel>
            <div className='mt-3'>
                <div>
                    <Card></Card>
                    <Card></Card>
                    <Card></Card>
                    <Card></Card>
                </div>
            </div>
        </>
    )
}

export default Home