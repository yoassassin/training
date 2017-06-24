using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using mvc3.micro.music_store.Models;

namespace mvc3.micro.music_store.Controllers
{
    public class StoreController : Controller
    {
        MusicStoreEntities storeDB = new MusicStoreEntities();

        // GET: Store
        public ActionResult Index()
        {
            //var genres = new List<Genre> {
            //    new Genre { Name = "Disco" },
            //    new Genre { Name = "Jazz"},
            //    new Genre { Name = "Rock"}
            //};
            var genres = storeDB.Genres.ToList();

            return View(genres);
        }

        //
        //Get: /store/Browse?genre=Disco
        public ActionResult Browse(string genre)
        {
            //var genreModel = new Genre { Name = genre };
            var genreModel = storeDB.Genres.Include("Albums").Single(g => g.Name == genre); //Include是Genre类里的Albums， 指定要包括在查询结果中的相关对象。
            //var genreModel = storeDB.Genres.Include("Albums").Where(g => g.Name == genre);//返回的是IQueryable的类，cshtml要的是genre类，single返回genre类

            /*
            Genre genreModelLinq;
            using (var context = new MusicStoreEntities())
            {
                 var a = from o in context.Genres.Include("Albums")
                                 where o.Name == genre
                                 select o;
                genreModelLinq = a.ToList().FirstOrDefault(); //FirstOrDefault返回的是单个对象
            }

            return View(genreModelLinq)
            */
            return View(genreModel);//前后台model的类型要匹配
        }

        //
        // Get: /store/Detail/5     can not implete for string as above func. 上面的string参数的方法不能用/Disco的形式
        // or   /store/detail?id=5  this is better.
        public ActionResult Detail(int id)
        {
            var album = storeDB.Albums.Find(id);
            return View(album);
        }
    }
}